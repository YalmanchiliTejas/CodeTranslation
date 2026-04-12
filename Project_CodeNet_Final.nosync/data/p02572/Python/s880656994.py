#入力:[n1,n2,...nk](int:整数配列)
def input_array():
	return list(map(int,input().split()))
  
n=int(input())
A=input_array()
acc_A=[0]

for i in range(n):
	acc_A.append(acc_A[i]+A[i])
ans=0
for i in range(n):
	ans+=A[i]*(acc_A[n]-acc_A[i+1])

print(ans %(10**9+7))