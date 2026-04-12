n = int(input())
s = list(input())
for i in range(len(s)):
    if s[i] == 'o':
        s[i] = True
    else:
        s[i] = False

state = [None]*n
state[0] = 1
state[1] = 1


def next_predict(before_state,current_state,output):#i+1の動物を出力する
    if current_state == 1:
        if output == True:
            if before_state == 1:
                return 1
            else:
                return 0
        else:
            if before_state == 1:
                return 0
            else:
                return 1
    else:
        return next_predict(before_state,1,not(output))

isFound = -1
for i in range(4):
    for j in range(1,n-1):
        state[j+1] = next_predict(state[j-1],state[j],s[j])
    tmp0 = next_predict(state[n-2],state[n-1],s[n-1])
    tmp1 = next_predict(state[n-1],state[0],s[0])
    if tmp0 == state[0] and tmp1 == state[1] :
        isFound = 1
        ans = []
        for k in range(n):
            if state[k] == 0:
                ans.append('W')
            else:
                ans.append('S')
        print("".join(ans))
        break
    else:
        if i == 0:
            state[1] = 0
        elif i == 1:
            state[0] = 0
        else:
            state[1] = 1

if isFound == -1:
    print(-1)
