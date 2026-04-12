N = int(input())
al = list(map(int,input().split()))
sss=0
pss=0
for i in range(1,N):
    pss+=al[i-1]
    sss+=al[i]*pss
print(sss%1000000007)