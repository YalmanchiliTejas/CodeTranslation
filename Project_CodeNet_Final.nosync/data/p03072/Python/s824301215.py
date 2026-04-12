N = int(input())
H = map(int, input().split())

count = 0
H_max = 0

for Hi in H:
    if H_max <= Hi:
        count += 1
        H_max = Hi

print(count)
