N = int(input())
H = [int(i) for i in input().split()]

ma = H[0]
count = 0
for hi in H:
    if hi >= ma:
        count += 1
        ma = hi
print(count)