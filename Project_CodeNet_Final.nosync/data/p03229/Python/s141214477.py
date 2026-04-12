import sys
n = int(input())
A = [int(sys.stdin.readline()) for _ in range(n)]
A.sort(reverse=True)
if n==2:
    print(A[0]-A[1])
elif n%2==0:
    ans = 0
    K = [2]*(max(0,n-2)//2)+[1,-1]+[-2]*(max(0,n-2)//2)
    print(sum([A[i]*K[i] for i in range(n)]))
else:
    K1 = [2]*(max(0,n-2)//2)+[1,1]+[-2]*(max(0,n-2)//2+1)
    K2 = [2]*(max(0,n-2)//2+1)+[-1,-1]+[-2]*(max(0,n-2)//2)
    print(max(sum([A[i]*K1[i] for i in range(n)]),
              sum([A[i]*K2[i] for i in range(n)])))