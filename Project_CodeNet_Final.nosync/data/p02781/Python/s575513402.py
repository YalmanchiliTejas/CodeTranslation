N=input()
K=int(input())
M=len(N)
dp=[[[0]*(K+1) for i in (0,1)] for j in range(M+1)]
dp[0][0][0]=1

for i in range(M):
   for smaller in (0,1):
      for no_zero_number in range(K+1):
         for x in range(10):
            #print("############")
            #print("i:",i)
            #print("smaller:",bool(smaller))
            #print("no_zero:",no_zero_number)
            #print("x:",x)
            if smaller==0 and x>int(N[i]):
               continue
            if x==0:
               dp[i+1][smaller or x<int(N[i])][no_zero_number]+=dp[i][smaller][no_zero_number]
            else:
               if no_zero_number+1>K:
                  continue
               else:
                  dp[i+1][smaller or x<int(N[i])][no_zero_number+1]+=dp[i][smaller][no_zero_number]
            #print(dp)
#print(dp)
print(dp[M][1][K]+dp[M][0][K])