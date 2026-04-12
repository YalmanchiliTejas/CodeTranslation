## coding: UTF-8

N, X, M = map(int,input().split())

fresh = [True] * M #まだついたことのない場所をTrueにしている
fresh[X] = False
turn = [-1] * M #なん回目におとづれたか記録する
turn[X] = 0
status = True


#print(fresh, turn)

def search_loop():
    log = [X] #訪れた地点を記録するもの
    last  = X #最後に訪れた地点を記録するもの（ここから次に行くところを検索する）
    counter = 0
    loop_count = -1
    loop_start = -1
    while status:
        #next_spot = A[last - 1]
        next_spot = (last * last) % M 
        counter += 1
        #print(next_spot)
        if(fresh[next_spot]):
            #処理を書く
            log.append(next_spot)
            last = next_spot
            fresh[next_spot] = False
            turn[next_spot] = counter
        else:
            log.append(next_spot)
            last = next_spot
            fresh[next_spot] = False
            loop_count = counter - turn[next_spot]
            loop_start = turn[next_spot]
            #最後の人処理をする
            break
    #print(len())
    return log, last, turn, counter, loop_count, loop_start

#print(search_loop())

ret = search_loop()
#print(ret)
log = ret[0]
last = ret[1]
turn = ret[2]
counter = ret[3]
loop_count = ret[4]
loop_start = ret[5]
#print(log)
#print(loop_count)
#print(loop_start)

#print(log, last, turn)
#print(N, counter)
if(N <= len(log)):
    ans = sum(log[:N])
else:
    ans = sum(log[:loop_start])
    #ans = -1
    #print(log[loop_start:len(log)-1])
    sum_loop = sum(log[loop_start:len(log)-1])
    mawaru_kaisuu = (N-loop_start) // loop_count
    #print(mawaru_kaisuu)
    ans += (sum_loop * mawaru_kaisuu)
    nokori = (N-loop_start) - (loop_count*mawaru_kaisuu)
    ans += sum(log[loop_start:loop_start+nokori]) 


print(ans)

