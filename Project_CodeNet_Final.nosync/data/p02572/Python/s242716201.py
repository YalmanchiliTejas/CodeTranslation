N = int(input())
A = list(map(int,input().split()))
p = 0
c = len(A) - 1
total = 0
while 0 < c:
    p += A[c]
    total = total + p * A[c-1]
    if total >= 1000000007:
        total %= 1000000007
    c -= 1

print(total)
