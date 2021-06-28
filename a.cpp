#include<bits/stdc++.h>
using namespace std;
void traverse(int **A,int x,int y,int m,int n,int dir){
	//upright = 1
	//downleft= 0
	//cout<<x<<" "<<y<<endl;
	if(x==m-1 && y==n-1){
		cout<<A[x][y]<<" ";
		return;
	}
	else if(((x<0) && dir==1) && (y>=n && dir==1)){
		traverse(A,x+2,y-1,m,n,0);
	}
	else if((x<0) && dir==1){
		dir=0;
		traverse(A,x+1,y,m,n,0);
	} 
	else if(y>=n && dir==1){
		traverse(A,x+2,y-1,m,n,0);
	}
	else if((x>=m && dir==0)&&(y<0 && dir==0)){
		traverse(A,x-1,y+2,m,n,1);
	}
	else if(x>=m){
		traverse(A,x-1,y+2,m,n,1);
	}
	else if(y<0){
		traverse(A,x,y+1,m,n,1);
	}
	else if(dir==0){
		cout<<A[x][y]<<" ";
		traverse(A,x+1,y-1,m,n,0);
	}
	else if(dir==1){
		cout<<A[x][y]<<" ";
		traverse(A,x-1,y+1,m,n,1);
	}
	else{
		cout<<"fuck"<<endl;
	}
}
int main(){
	int m,n;cin>>m>>n;
	//int A[m][n];
	int **A;
	A = new int*[m];
	for(int i=0;i<m;i++){
		A[i] = new int[n];
		for(int j=0;j<n;j++){
			cin>>A[i][j];
		}
	}
	traverse(A,0,0,m,n,1);
}
