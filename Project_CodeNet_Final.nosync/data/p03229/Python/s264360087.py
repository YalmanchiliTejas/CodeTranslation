import sys
readline = sys.stdin.buffer.readline
def even(n): return 1 if n%2==0 else 0
n = int(readline())
lst1 = []
for i in range(n):
    lst1.append(int(readline()))
lst1.sort(reverse=True)
if n % 2 == 1:
    minority = n//2
    majority = n - minority
    A = sum(lst1[:minority])*2 - sum(lst1[minority:])*2+sum(lst1[minority:minority+2])
    B = sum(lst1[:majority])*2 - sum(lst1[majority:])*2 - sum(lst1[majority-2:majority])
    ans = max(A, B)
else:
    C = sum(lst1[:n//2])*2 - sum(lst1[n//2:])*2 + lst1[n//2]-lst1[n//2-1]
    D = -C
    ans = max(C, D)
print(ans)
