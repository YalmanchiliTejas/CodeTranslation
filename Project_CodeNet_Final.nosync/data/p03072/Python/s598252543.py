N = int(input())
H = [int(s) for s in input().split()]

count = 1
for i in range(1, len(H)):
    pred = [c <= H[i] for c in H[:i]]
    if all(pred):
        count += 1
        
print(count)