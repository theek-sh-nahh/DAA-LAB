#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

int count; 

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int* arr, int l, int r){

	if (l<r){
		int p = l;
		int i=l;
		int j=r;
		
		while(i<j){
			while(arr[i]<=arr[p] && i<r) {
			i++;
			count++;
			}
			while(arr[j]>arr[p]) {
			j--;
			count++;
			}
			if (i<j) swap(&arr[i],&arr[j]);
		}
		
		swap(&arr[j],&arr[p]);
		quickSort(arr,l,j-1);
		quickSort(arr,j+1,r);
	}

}

void main(){

	int *arr,n,i; 
	
	FILE *fp1, *fp2, *fp3; 
	
	system("rm best.txt avg.txt worst.txt"); 
	
	srand(time(0));
	
	for(n=10;n<1000;n+=10){ 
	
		arr = (int*)malloc(n*sizeof(int)); 
		
		
		//Best Case - yet to work on case
		count=0; 
		for(i=0;i<n;i++){
			arr[i] = 1; //change this
		}	
		quickSort(arr,0,n-1);
		fp1 = fopen("best.txt","a"); 
		fprintf(fp1,"%d\t%d\n", n,count); 
				
		
		//Average Case
		count=0;  
		for(i=0;i<n;i++){
			arr[i] = rand()%100; 
		}
		quickSort(arr,0,n-1); 
		fp2 = fopen("avg.txt","a"); 
		fprintf(fp2,"%d\t%d\n", n,count); 
		
		
		//Worst Case
		count=0;
		for(i=0;i<n;i++){
			arr[i] = (i==0)? rand()%100 : arr[i-1]+rand()%10; 
		}
		quickSort(arr,0,n-1);
		fp3 = fopen("worst.txt","a"); 
		fprintf(fp3,"%d\t%d\n", n,count);
	}
	
	fclose(fp1); fclose(fp2); fclose(fp3); 
}