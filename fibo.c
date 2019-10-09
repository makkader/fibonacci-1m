/**** Compiling instruction ****
compile: clang -O3 fibo.c -o fibo.out
run: ./fibo.out
The n-th fibonacci number will be written in a file named 'nthFibonacci'
*/


/*
Author: Mak Kader
Email: abdul.kader880@gmail.com
*/

#include<stdio.h>
#include<stdlib.h>

#define SZ 56000
typedef  unsigned long long int TYPE;
int len=1;
const TYPE BASE=1e19;

//output
void toString(TYPE *a){
	int i;
	printf("%llu",a[len-1]);
	for(i=len-2;i>=0;i--){
		printf("%019llu",a[i]);
	}
	printf("\n");
	
}
void writeResult(TYPE *a){
	int i;
	FILE *fp;
	fp = fopen ("nthFibonacci", "w");
	fprintf(fp,"%llu",a[len-1]);
	for(i=len-2;i>=0;i--){
		fprintf(fp,"%019llu",a[i]);
	}
	fprintf(fp,"\n");
	fclose(fp);
}

//end output


TYPE * computeNthFibo(int N){
	
	TYPE *a,*b,*c,*temp;
	int j,i;
	TYPE carry;

	
	a=(TYPE*) calloc(SZ,sizeof(TYPE));
	b=(TYPE*) calloc(SZ,sizeof(TYPE));
	c=(TYPE*) calloc(SZ,sizeof(TYPE));

	b[0]=1;
	
	if (N<=1) return a;

	

	for (j=3;j<=N;j++){
		//add previous two fibos
		i=0;
		carry=0;
		while(i<len){
		
			carry=carry+b[i]; //carry is b
			if (BASE-a[i]<=carry){
				c[i]=carry-(BASE-a[i]);
				carry=1;
			}
			else {
				c[i]=carry+a[i];
				carry=0;
			}
			i++;
		}
		if (carry){
			c[len++]=carry;
		}
		
		

		temp=a;
		a=b;
		b=c;
		c=temp;
		
	}
	return b;

}

int main(int argc,char *argv[]){

	int N=1;
	if (argc==1){
		printf("Please Enter  N: ");
		scanf("%d",&N);
	}
	else
		N=atoi(argv[1]);

	TYPE *res=computeNthFibo(N);
	//toString(res);
	writeResult(res);
	
	return 0;	

}