n,k = map(int,input().split())
print(n**2 if not k else sum([(i-k)*(n//i)+max(0,n%i-k+1) for i in range(k+1,n+1)]))