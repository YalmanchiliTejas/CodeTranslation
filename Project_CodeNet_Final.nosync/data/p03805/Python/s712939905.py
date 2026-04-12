N,M=map(int,input().split())
original_paths={}
paths={}
for n in range(1,N+1):
    original_paths[n]=[]
    paths[n]=[]
for m in range(1,M+1):
    s,e=map(int,input().split())
    original_paths[s].append(e)
    original_paths[e].append(s)
    paths[s].append(e)
    paths[e].append(s)#以上地図作り
    
visited=[1]
current_point=1
answer=0

while len(paths[1])!=0:#すべてのルートを探索済み==点1から動けない
    
    if len(paths[current_point])!=0:
        next_point=paths[current_point][0]
    
        if next_point in visited:#next_pointに行ったことがある

            if len(paths[current_point])!=1:#next_point以外に選択肢がある
                paths[current_point].remove(next_point)#next_pointを選択肢から消す

            else:#next_point以外に選択肢がない(current_pointは行き止まり)
                if len(visited)==N:#すべての点を訪れたかチェック
                    answer+=1
                prior_point=visited[-2]#ひとつ前にいた点をprior_pointとし、
                paths[current_point]=original_paths[current_point].copy()#current_pointからの選択肢を初期化
                paths[prior_point].remove(current_point)#prior_pointの選択肢からcurrent_pointを除く
                visited.remove(current_point)#current_pointをvisitedから除き、
                current_point=prior_point#prior_pointに戻る

        else:#next_pointに行ったことがない
            visited.append(next_point)#next_pointをvisitedに加え、
            current_point=next_point#next_pointに進む

    else:
        prior_point=visited[-2]#ひとつ前にいた点をprior_pointとし、
        paths[current_point]=original_paths[current_point].copy()#current_pointからの選択肢を初期化
        paths[prior_point].remove(current_point)#prior_pointの選択肢からcurrent_pointを除く
        visited.remove(current_point)#current_pointをvisitedから除き、
        current_point=prior_point#prior_pointに戻る
        
print(answer)
