h, w = map(int,input().split())
a = [input() for _ in range(h)]
c = 0

#行の中で「....」があれば取り除く.
while "."*w in a:
    a.remove("."*w) #removeは該当要素のうち最初の要素を削除
    c += 1
    
#行と列の入れ替え
a = ["".join(column) for column in zip(*a)]
while "."*(h-c) in a:
    a.remove("."*(h-c))

#行と列を再度入れ替えて出力.
for row in zip(*a):
    print("".join(row))