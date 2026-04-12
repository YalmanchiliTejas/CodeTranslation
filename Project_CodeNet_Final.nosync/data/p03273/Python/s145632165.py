H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]

remove_H = []
w_count = [0] * W
for h in range(H):
    if "#" in A[h]:
        remove_H.append(A[h])
        for i, w in enumerate(A[h]):
            if w == "#":
                w_count[i] += 1
remove_W = set([i for i, x in enumerate(w_count) if x != 0])
for h in remove_H:
    ans = [h[i] for i in range(W) if i in remove_W]
    print("".join(ans))