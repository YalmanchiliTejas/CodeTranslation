n = int(input())
#文字列を一列ごとにリストに入れる
S = [input() for _ in range(n)]
alphabet_str = "abcdefghijklmnopqrstuvwxyz"
#alphbetの文字列をリスト化
alphabets = list(alphabet_str)

s_maps = []
for s in S:
#sはSの文字列の一つ一つ
#文字列sをリスト化    
    strs = list(s)
#辞書を作る
    m = {}
#各alphbetの初期値を0にする
    for alphabet in alphabets:
        m[alphabet] = 0
#文字列の中にあるalphabetがあれば、辞書のvalueに1を追加
    for _str in strs:
        m[_str] += 1
#辞書をリストに突っ込む      
    s_maps.append(m) 
#print(s_maps)
ans = ""
#alphabetリストからalphabetを取り出す
for alphabet in alphabets:
    min_num = 51
#リストから辞書を一つずつ取り出す    
    for s_map in s_maps:
#n個の辞書の中から最小のvalueを取り出す
        min_num = min(s_map[alphabet], min_num)
    for i in range(min_num):
        ans += alphabet
print(ans)
#taku689さんのコードを大いに参考