N=int(input())
A=list(map(int,input().split()))
mod=pow(10,9)+7
numbers=[]
num=0
for a in A:
    num+=a
    numbers.append(num)
ans=0
last=numbers[-1]
for n in range(N-1):
    number=numbers[n+1]-numbers[n]
    ans+=(number*(last-numbers[n+1]))
ans+=(A[0]*(last-A[0]))
ans=ans%mod
print(ans)
