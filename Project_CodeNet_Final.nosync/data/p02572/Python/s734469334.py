x = 7+10**9
n=int(input())
ans=0
list = list(map(int,input().split()))
s=sum(list)
for i in list:
    s -=i
    ans += i*s
print(ans%x)