N = int(input())
A = []
for i in range(N):
    A.append(int(input()))
A.sort()

PLUS = A[int((N+1)//2):]
MINUS = A[:int((N+1)//2)]
#print(PLUS, MINUS)
ans = sum(PLUS)*2 - sum(MINUS)*2
if N%2==0:
    ans += MINUS[-1] - PLUS[0]
else:
    ans += sum(MINUS[-2:])

PLUS = A[int(N//2):]
MINUS = A[:int(N//2)]
#print(PLUS, MINUS)
ans2 = sum(PLUS)*2 - sum(MINUS)*2
if N%2==0:
    ans2 += MINUS[-1] - PLUS[0]
else:
    ans2 -= sum(PLUS[:2])

print(max(ans, ans2))