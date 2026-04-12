n=int(input())
li = list(map(int,input().split()))	
ruiseki=[0]*(n+1)
for i in range(n):
    ruiseki[i+1]=ruiseki[i]+li[i]
ans=0
for i in range(0,n-1):
    ans+=(li[i]*(ruiseki[-1]-ruiseki[i+1]))%((10**9)+7)
print(ans%((10**9)+7))