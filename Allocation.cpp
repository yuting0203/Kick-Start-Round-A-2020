#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int tc;
	int n, b;
	int a[100001];
	int ans;
	scanf("%d\n", &tc);
	for(int k=1; k<=tc; k++){
		ans=0;
		scanf("%d %d\n", &n, &b);
		for(int i=0; i<n; i++){
			scanf("%d" ,&a[i]);
		}
		sort(a,a+n);
		for(int i=0; a[i]<=b&&i<n; i++){
			ans++;
			b-=a[i];
		}
		if(k!=1) printf("\n");
		printf("Case #%d: %d", k, ans);
	}
	return 0;
}
