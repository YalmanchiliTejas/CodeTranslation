n = int(input())
l0 = list(map(int, input().split()))
l = sorted(l0)

m1 = l[n//2 - 1]
m2 = l[n//2]
for i in range(len(l0)):
    if l0[i] < m2:
        print(m2)
    elif l0[i] > m1:
        print(m1)
    elif l0[i] == m1:
        print(m2)
    elif l0[i] == m2:
        print(m1)