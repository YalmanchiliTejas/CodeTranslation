from itertools import product
N = int(input())
S = input()

C = product("SW", repeat=2)


for c in C:
    ans = list(c)
    for i in range(1, len(S)):
        # 羊
        if ans[-1] == "S":
            # 羊で〇なら同じ
            if S[i] == "o":
                ans.append(ans[-2])
            else:
                # 羊で×ならじゃないほう
                if ans[-2] == "S":
                    ans.append("W")
                else:
                    ans.append("S")
        # 狼
        else:
            # 狼で×なら同じ
            if S[i] == "x":
                ans.append(ans[-2])
            # 狼で〇ならじゃないほう
            else:
                if ans[-2] == "S":
                    ans.append("W")
                else:
                    ans.append("S")

    ans = ans[:-1]
    for i in range(N):
        if ans[i] == "S" and S[i] == "o":
            if ans[i-1] != ans[(i+1) % N]:
                break
        if ans[i] == "S" and S[i] == "x":
            if ans[i-1] == ans[(i+1) % N]:
                break
        if ans[i] == "W" and S[i] == "x":
            if ans[i-1] != ans[(i+1) % N]:
                break
        if ans[i] == "W" and S[i] == "o":
            if ans[i-1] == ans[(i+1) % N]:
                break
    else:
        print("".join(ans))
        break

else:
    print(-1)
