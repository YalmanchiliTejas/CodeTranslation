N = int(input())
s = input()

# idx=0にN番目の動物、idx=N+1に1番目の動物
ansS = [""] * (N+2)
ansW = [""] * (N+2)
ansS[1] = ansS[N+1] = "S" # 1番目がSの場合
ansW[1] = ansW[N+1] = "W" # 1番目がWの場合
# N番目がSと仮定する
ansS[0] = ansS[N] = "S" 
ansW[0] = ansW[N] = "S" 
for i in range(N):
    
    if s[i] == "o": 
        ansS[i+2] = "S" if ((ansS[i+1] == "S" and ansS[i] == "S") or (ansS[i+1] == "W" and ansS[i] == "W")) else "W"
        ansW[i+2] = "S" if ((ansW[i+1] == "S" and ansW[i] == "S") or (ansW[i+1] == "W" and ansW[i] == "W")) else "W"
    else:
        ansS[i+2] = "S" if ((ansS[i+1] == "S" and ansS[i] == "W") or (ansS[i+1] == "W" and ansS[i] == "S")) else "W"
        ansW[i+2] = "S" if ((ansW[i+1] == "S" and ansW[i] == "W") or (ansW[i+1] == "W" and ansW[i] == "S")) else "W"

if ansS[0] == ansS[N] and ansS[1] == ansS[N+1]:
    print("".join(ansS[1:N+1]))
    exit()

if ansW[0] == ansW[N] and ansW[1] == ansW[N+1]:
    print("".join(ansW[1:N+1]))
    exit()


# idx=0にN番目の動物、idx=N+1に1番目の動物
ansS = [""] * (N+2)
ansW = [""] * (N+2)
ansS[1] = ansS[N+1] = "S" # 1番目がSの場合
ansW[1] = ansW[N+1] = "W" # 1番目がWの場合
# N番目がSと仮定する
ansS[0] = ansS[N] = "W" 
ansW[0] = ansW[N] = "W" 

for i in range(N):
    
    if s[i] == "o": 
        ansS[i+2] = "S" if ((ansS[i+1] == "S" and ansS[i] == "S") or (ansS[i+1] == "W" and ansS[i] == "W")) else "W"
        ansW[i+2] = "S" if ((ansW[i+1] == "S" and ansW[i] == "S") or (ansW[i+1] == "W" and ansW[i] == "W")) else "W"
    else:
        ansS[i+2] = "S" if ((ansS[i+1] == "S" and ansS[i] == "W") or (ansS[i+1] == "W" and ansS[i] == "S")) else "W"
        ansW[i+2] = "S" if ((ansW[i+1] == "S" and ansW[i] == "W") or (ansW[i+1] == "W" and ansW[i] == "S")) else "W"

if ansS[0] == ansS[N] and ansS[1] == ansS[N+1]:
    print("".join(ansS[1:N+1]))
    exit()

if ansW[0] == ansW[N] and ansW[1] == ansW[N+1]:
    print("".join(ansW[1:N+1]))
    exit()

print(-1)