N=int(input())
B=[int(a) for a in input().split()]

sum=0
ans=0
for i in range(len(B)-1):
    sum+=B[i]
    ans+=sum*B[i+1]
print(ans%1000000007)
