while True:
    n = int(raw_input())
    if n == 0: break
 
    else:
        list = []
        for i in range(n):
            score = int(raw_input())
            list.append(score)
        list.sort();
        list.pop(0);
        list.pop();
        x = sum(list) / (n-2)
        print x