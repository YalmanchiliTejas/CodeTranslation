import bisect
def main():
    N = int(input())
    A = []
    c = 1
    l = []
    for _ in range(N):
        a = int(input())
        A.append(a)
    l.append(A[-1])
    for j in reversed(A[:-1]):
        i = bisect.bisect_right(l, j)
        if i == len(l):
            l.append(j)
        else:
            l[i] = j
    print(len(l))
main()

