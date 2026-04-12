H, W = map(int, input().split())
A = [input() for _ in range(H)]
A = [aa for aa in A if any(a=="#" for a in aa)]
A = list(map(list, zip(*A)))
A = [aa for aa in A if any(a=="#" for a in aa)]
A = list(map(list, zip(*A)))
for aa in A:
    print("".join(aa))