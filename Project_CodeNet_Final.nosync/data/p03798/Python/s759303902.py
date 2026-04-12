def swap(w):
    return("S" if w == "W" else "W")

N = int(input())
s = input()

inits = ["SS","SW","WS","WW"]

for init in inits:
    ans = init
    for i in range(1,N):
        if(ans[i] == 'S'):
            if(s[i] == 'o'):
                ans = ans + ans[i-1]
            else:
                ans = ans + swap(ans[i-1])
        else:
            if(s[i] == 'o'):
                ans = ans + swap(ans[i-1])
            else:
                ans = ans + ans[i-1]

    if(ans[0] == ans[-1]):
        ans = ans[0:N]

        if(ans[0] == 'S'):
            if(s[0] == 'o'):
                val = (ans[1] == ans[-1])
            else:
                val = (ans[1] != ans[-1])
        else:
            if(s[0] == 'o'):
                val = (ans[1] != ans[-1])
            else:
                val = (ans[1] == ans[-1])
        
        if(val):
            break

    ans = "-1"

print(ans)