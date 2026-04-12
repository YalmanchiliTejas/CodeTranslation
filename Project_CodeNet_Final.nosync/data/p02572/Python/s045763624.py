N = int(input())
Alist = list(map(int,input().split()))
M = 10**9+7
Asum = sum(Alist)
Answer = 0
for i in range(len(Alist)):
    Asum -= Alist[i]
    Answer += (Alist[i]%M)*(Asum%M)
    Answer = Answer%M
print(Answer)