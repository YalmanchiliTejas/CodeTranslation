h, w = map(int, input().split())
data = []
for _ in range(h):
    data.append( list(input()) )

next_data = []
# 横列処理
for d in data:
    if "#" in d:
        next_data.append( d )

next_next_data = []
origin_v_data = []
# 縦列処理
for i in range( len(next_data[0]) ):
    # 縦配列生成
    v_data = []
    for j in range( len(next_data) ):
        v_data.append( next_data[j][i] )

    # 配列チェック
    if "#" in v_data:
        origin_v_data.append( v_data )

ans_data = []
for i in range( len(origin_v_data[0]) ):
    join_data = []
    for j in range( len(origin_v_data) ):
        join_data.append( origin_v_data[j][i] )
    ans_data.append( join_data )

# 標準出力
for a in ans_data:
    print("".join(a))
