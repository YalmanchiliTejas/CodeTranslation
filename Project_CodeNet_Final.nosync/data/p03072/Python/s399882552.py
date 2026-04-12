N = input().split()
H = list(map(int, input().split()))
H0 = H[0]
count = 1
for i in H[1:]:
    if H0 <= i:
        count += 1
        H0 = i
print(count)