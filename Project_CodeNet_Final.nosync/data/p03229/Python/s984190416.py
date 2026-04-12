n = int(input())
a = [int(input()) for i in range(n)]

a = sorted(a)


s_a = a[0:n//2]
l_a = a[n//2:]

if len(s_a) == len(l_a):
    print(2*sum(l_a) - l_a[0] - 2*sum(s_a) + s_a[-1])

else:
    tmp_ans1 = 2*sum(l_a) - l_a[0] - l_a[1] - 2*sum(s_a)    
    s_a = a[0:n//2+1]
    l_a = a[n//2+1:]
    tmp_ans2 = 2*sum(l_a) - 2*sum(s_a) + s_a[-2] + s_a[-1]
    print(max(tmp_ans1, tmp_ans2))
