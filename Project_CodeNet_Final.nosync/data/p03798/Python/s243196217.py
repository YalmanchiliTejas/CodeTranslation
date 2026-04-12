N = int(input())
ori1 = [0 for x in  range(N)]
fini = 0
s = input()

init = [[1,1],[1,-1],[-1,1],[-1,-1]]


for it in init:
    flag = 0
    ori = ori1.copy()
    ori[0] = it[0]
    ori[1] = it[1]
    for i in range(N):
        if i == 0:
            continue
        if ori[i] == 1:
            if s[i] == "o":
                if i == N-1:
                    if ori[0] != ori[i-1]:
                        flag = 1

                else:
                    ori[i+1] = ori[i-1]
            else:
                if i == N-1:
                    if ori[0] != -ori[i-1]:
                        flag = 1
                else:
                    ori[i+1] = -ori[i-1]
        else:
            if s[i] == "x":
                if i == N-1:
                    if ori[0] != ori[i-1]:
                        flag = 1
                else:
                    ori[i+1] = ori[i-1]
            else:
                if i == N-1:
                    if ori[0] != -ori[i-1]:
                        flag = 1
                else:
                    ori[i+1] = -ori[i-1]
    if ori[0] == 1:
        if s[0] == "o":
            if ori[1] != ori[-1]:
                flag = 1
        else:
            if ori[1] == ori[-1]:
                flag = 1
    else:
        if s[0] == "x":
            if ori[1] != ori[-1]:
                flag = 1
        else:
            if ori[1] == ori[-1]:
                flag = 1

    if flag == 0:
        ori = ["S" if x == 1 else "W" for x in ori]
        out = ""
        for o in ori:
            out += o
        print(out)
        fini = 1
        break
    else:
        continue

if fini == 0:
    print(-1)