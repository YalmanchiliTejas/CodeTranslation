N=int(input())
A=[]
for i in range(N):
    n=int(input())
    A.append(n)
A.sort()
if N%2==1:
    ans1=0
    B=A[int(N/2)]
    for j in range(int(N/2)):
        ans1+=abs(B-A[j])
        B=A[j]
        ans1+=abs(B-A[N-1-j])
        B=A[N-1-j]
    ans2=0
    C=A[int(N/2)]
    for k in range(int(N/2)):
        ans2+=abs(C-A[N-1-k])
        C=A[N-1-k]
        ans2+=abs(C-A[k])
        C=A[k]
    print(max(ans1,ans2))
else:
    ans1=0
    B=A[int(N/2)]
    for j in range(int(N/2)-1):
        ans1+=abs(B-A[j])
        B=A[j]
        ans1+=abs(B-A[N-1-j])
        B=A[N-1-j]
    ans1+=abs(B-A[int(N/2)-1])
    ans2=0
    C=A[int(N/2)-1]
    for k in range(int(N/2)-1):
        ans2+=abs(C-A[k])
        C=A[k]
        ans2+=abs(C-A[N-1-k])
        C=A[N-1-k]
    ans2+=abs(C-A[int(N/2)])
    print(max(ans1,ans2))