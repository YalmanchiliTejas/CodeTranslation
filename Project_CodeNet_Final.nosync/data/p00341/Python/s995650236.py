#標準入力
l = list(map(int,input().split()))

#リストを小さい順に並べる
l.sort()

#4辺を1人組とし、1組の辺が全て同じであれば"yes"でなければ"no"を出力する
if l[0] == l[1] == l[2] == l[3] and l[4] == l[5] == l[6] == l[7] and l[8] == l[9] == l[10] == l[11]:print("yes")
else:print("no")
