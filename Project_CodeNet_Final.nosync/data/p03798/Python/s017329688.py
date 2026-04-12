N = int(input())
s = input()

def makeans(ans):
        for c in s:
                if (ans[-1] == "S") ^ (c == "o") ^ (ans[-2] == "W"):
                        ans += "W"
                else:
                        ans += "S"

        return ans

for initial in ["SS","SW","WS","WW"]:
        ans = makeans(initial)
        if ans[0] == ans[-2] and ans[1] == ans[-1]:
                print(ans[1:-1])
                exit()

print("-1")