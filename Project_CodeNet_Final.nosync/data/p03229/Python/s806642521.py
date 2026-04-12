n = int(input())
a = sorted([int(input()) for i in range(n)])
b = list(a[::-1])



def f(A):
    l = r = A.pop(0)

    ans = 0

    for i in range(len(A)//2):
        if i % 2 == 0:
            ans += abs(l - A[-1]); l = A.pop(-1);
            ans += abs(r - A[-1]); r = A.pop(-1);
        else:
            ans += abs(l - A[0]); l = A.pop(0);
            ans += abs(r - A[0]); r = A.pop(0);
    if (A):
        ans += abs(l - A[0])

    return ans


print(max(f(a), f(b)))