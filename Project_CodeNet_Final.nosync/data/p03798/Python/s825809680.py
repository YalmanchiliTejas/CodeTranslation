from itertools import product
n = int(input())
s = input()
s_dict = {"o":1, "x":-1}
flg = False
for combi in product([-1,1], repeat=2):
    state = list(combi)
    for i, _s in enumerate(s[1:], 1):
        cur = state[i]
        res = s_dict[_s] * cur * state[i-1]
        state.append(res)
    if state[0] == state[-1] and state[n-1] == state[0] * state[1] * s_dict[s[0]]:
        flg = True
        break
res = "".join(["S" if i == 1 else "W" for i in state])
if flg:
    print(res[:-1])
else:
    print(-1)