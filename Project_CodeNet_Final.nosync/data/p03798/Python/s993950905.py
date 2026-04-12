def match(index_num):
    if answer[index_num] == "S":
        if s[index_num] == "o":
            if answer[(index_num+1)%N] == answer[index_num-1]:
                return True
        else:
            if answer[(index_num+1)%N] != answer[index_num-1]:
                return True
    else:
        if s[index_num] == "o":
            if answer[(index_num+1)%N] != answer[index_num-1]:
                return True
        else:
            if answer[(index_num+1)%N] == answer[index_num-1]:
                return True
    return False
 
N = int(input())
s = list(input())
SorW = ["S","W"]
 
for i in SorW:
    for j in SorW:
        answer = []
        append = answer.append
        append(i)
        append(j)
 
        for k in range(2,N):
            if answer[k-1] == "S":
                if s[k-1] == "o":
                    append(answer[k-2])
                else:
                    if answer[k-2] == "S":
                        append("W")
                    else:
                        append("S")
            else:
                if s[k-1] == "o":
                    if answer[k-2] == "W":
                        append("S")
                    else:
                        append("W")
                else:
                    append(answer[k-2])
        
        for k in [0,N-1]:
            if not match(k):
                break
            if k == N-1:
                print("".join(answer))
                exit()
print(-1)