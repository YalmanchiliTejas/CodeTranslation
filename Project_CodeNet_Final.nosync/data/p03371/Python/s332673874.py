pa, pb, pab, na, nb = map(int, input().split())

'''
1. そのまま
2. 少ない方全てをabで

3. abいっぱいで余らせる
'''

ans1 = pa * na + pb * nb
ans2 = pab * min(na, nb) * 2 + (pa if(na > nb) else pb) * abs(na - nb)
ans3 = pab * max(na, nb) * 2

print(min(ans1, ans2, ans3))
