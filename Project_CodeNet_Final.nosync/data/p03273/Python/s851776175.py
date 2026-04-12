def solve():
    H, W = map(int, input().split())
    A = []
    for _ in range(H):
        inp = [s for s in input()]
        if inp != ['.']*W:
            A.append(inp)
    Ans = list(zip(*A))
    P = ['.' for _ in range(len(A))]
    while tuple(P) in Ans:
        Ans.remove(tuple(P))
    Ans = list(zip(*Ans))
    for i in range(len(Ans)):
        Ans[i] = ''.join(Ans[i])
    return Ans
print(*solve(),sep='\n')