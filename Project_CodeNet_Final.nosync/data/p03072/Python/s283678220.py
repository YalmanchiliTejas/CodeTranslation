_ = input()
H = list(map(int, input().strip().split(' ')))

print(sum([1 if max(H[0:i]) <= H[i] else 0 for i in range(1,len(H))])+1)
