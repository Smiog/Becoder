#include "testlib.h"
#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <cstring>
#include <ctime>
#include <cmath>
#include <assert.h> 
using namespace std;
int n;
long long m,a[300005];
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int fullScore=100;
    n=inf.readInt(),m=inf.readLong();
    for(int i=1;i<=n;i++)a[i]=inf.readLong();
    int st=ouf.readInt();
    if(st<0||st>850000){
    	quitf(_wa, "Wrong Answer receive signal 1. (%d operations)",st);
    	return 1;
	}
    for(int i=1;i<=st;i++){
    	int x,y;
    	x=ouf.readInt(),y=ouf.readInt();
    	if(x<0||x>n||y<0||y>n){
	    	quitf(_wa, "Wrong Answer receive signal 2.");
	    	return 2;
		}
    	if(x==y){
	    	quitf(_wa, "Wrong Answer receive signal 3.");
	    	return 3;
		}
		if(a[x]<a[y]){
	    	quitf(_wa, "Wrong Answer receive signal 4.");
	    	return 4;
		}
		a[x]-=a[y],a[y]*=2;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)if(a[i]!=0)cnt++;
	if(cnt<=2)quitf(_ok, "Accepted! (%d operations)",st);
	else{
		double P=1.0*(n-max(cnt,2))/(n-2);
		P=min(P+0.05,0.8);
		int GetScore=(int)(P*fullScore);
		quitp(GetScore,"%.9f%% Score!",P*100);
		return 5;
	}
	return 0;
}
/*
*/
