while True:
    S = input()
    if S=="#":
        exit()
    B = []
    W = 0
    for c in S:
        if c == "b":
            B.append(1)
        elif c != "/":
            B.extend([0] * int(c))
        elif W==0:
            W = len(B)
    assert len(B) % W == 0
    H = len(B) // W
    a,b,c,d = map(lambda x: int(x)-1, input().split())
    B[a*W+b] = 0
    B[c*W+d] = 1
    ans = ""
    cnt = 0
    for y in range(H):
        for x in range(W):
            if B[y*W+x] == 0:
                cnt += 1
            else:
                if cnt>0:
                    ans+=str(cnt)
                cnt = 0
                ans += "b"
        if cnt>0:
            ans += str(cnt)
        cnt = 0
        ans += "/"
    print(ans[:-1])

