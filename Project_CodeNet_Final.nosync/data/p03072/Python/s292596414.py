N = input()
N = int(N)

a = list(map(int, input().split()))
a.reverse()

i = 0
while i < N:
    b = max(a)
    c = a.index(b)
    d = a[c+1:]

    i += 1
    if d == []:
        break
    a = d

print(i)