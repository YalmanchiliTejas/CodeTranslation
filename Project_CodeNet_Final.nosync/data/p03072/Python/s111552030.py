n=int(input())  #数値入力
list_h=list(map(int, input().split()))  #リスト入力

score  = 1
for i,h in enumerate(list_h[1:]):
    score += (max(list_h[:i+1]) <= h) * 1
print(score)