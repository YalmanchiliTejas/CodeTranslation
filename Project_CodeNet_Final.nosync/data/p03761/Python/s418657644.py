n = int(input())
s_common = list(input())
s_common_pre = ""
for i in range(n-1):
    s = list(input())
    s_common_pre = s_common.copy()
    len_common = len(s_common_pre)
    for i in range(len_common):
        if s_common_pre[i] in s:
            s.remove(s_common_pre[i])
        else:
            s_common.remove(s_common_pre[i])

s_common.sort()
s_common = "".join(s_common)
print(s_common)
