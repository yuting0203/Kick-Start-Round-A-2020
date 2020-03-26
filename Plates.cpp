#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
    int n, k, p;
    int tc;
    int tmp;
    int sum[51][31];
    int dp[51][1501];
    
    scanf("%d", &tc);
    for(int t=1; t<=tc; t++){
        scanf("%d %d %d", &n, &k, &p);
        memset(sum, 0, sizeof(sum));
        memset(dp, 0, sizeof(dp));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){
                scanf("%d", &tmp);
                sum[i][j]=sum[i][j-1]+tmp;
            }
        }
        
        for(int i=1; i<=k; i++)
            dp[1][i]=sum[1][i];
            
        for(int i=2; i<=n; i++){
            for(int j=1; j<=p; j++){
                for(int l=0; l<=min(j,k); l++){
                    dp[i][j]=max(dp[i][j], dp[i-1][j-l]+sum[i][l]);
                }
            }
        }
        
        if(t!=1) printf("\n");
        printf("Case #%d: %d", t, dp[n][p]);
    }
    return 0;
}
        
