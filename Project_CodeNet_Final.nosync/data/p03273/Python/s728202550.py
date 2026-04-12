import numpy as np
def f(s):
    s = s.replace('.', '0')
    s = s.replace('#', '1')
    lst = [int(n) for n in s]
    return np.array(lst)
h, w = list(map(int, input().split()))
a = np.array([f(input()) for i in range(h)])
b = a[:, ~np.all(a==0, axis=0)]
ans_ = b[~np.all(a==0, axis=1)]
ans = ans_.tolist()
for i in range(len(ans)):
    out3 = [str(n) for n in ans[i]]
    out2 = ''.join(out3)
    out1 = out2.replace('0', '.')
    out0 = out1.replace('1', '#')
    print(out0)