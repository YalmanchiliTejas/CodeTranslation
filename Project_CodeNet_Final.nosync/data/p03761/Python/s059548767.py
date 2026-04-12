#58c
import collections

n = int(input())

#初回分だけ別処理
s = str(input()) 
s_counted = collections.Counter(s)
alphabet_times_dict = dict(s_counted)

#初回分以降を読み込んで、重なっている文字と回数を絞っていく
for i in range(n-1):
    s = str(input()) 
    s_counted = collections.Counter(s)
    
    for alphabet_times in alphabet_times_dict.items():
        alphabet = alphabet_times[0]
        times = alphabet_times[1]
        
        if alphabet in s_counted:
            alphabet_times_dict[alphabet] = min(alphabet_times_dict[alphabet],s_counted[alphabet])
        else:
            alphabet_times_dict[alphabet] = 0

#重なっていた文字＊回数のリスト作成
string_list = []

for alphabet_times in alphabet_times_dict.items():
    alphabet = alphabet_times[0]
    times = alphabet_times[1]
    
    if times != 0:
        string_list += [alphabet for i in range(times)]
        
#辞書順に並び替えて表示
string_list.sort(reverse = False)
print(''.join(map(str,string_list)))