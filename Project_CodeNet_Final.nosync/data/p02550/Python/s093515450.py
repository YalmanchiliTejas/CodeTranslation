# %
n, x, m = map(int, input().split())
import sys

result = [x]
pat = set()
pat.add(x)
flg = False
for _ in range(n - 1):
    tmp = pow(result[-1], 2, m)
    if tmp in pat:
        flg = True
        break
    elif tmp == 0:
        print(sum(result))
        sys.exit()
    else:
        result.append(tmp)
        pat.add(tmp)
        
if not flg:
    print(sum(result))

else:
    cnt = result.index(tmp)
    cycle = result[-(len(result) - cnt):]
    rest = (n - cnt)
    print(sum(result[:cnt]) + (rest // len(cycle)) * sum(cycle) + sum(cycle[:rest % len(cycle)]))