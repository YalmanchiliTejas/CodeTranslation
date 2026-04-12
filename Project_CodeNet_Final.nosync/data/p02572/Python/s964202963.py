n=int(input())
a=list(map(int,input().split()))
s2=int(sum(a)*sum(a))
a2=[int(i*i) for i in a]
ans1=int((s2-sum(a2))//2)
print(int(ans1%(10**9+7)))