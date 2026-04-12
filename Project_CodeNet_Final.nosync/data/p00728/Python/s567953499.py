while True: #無限に繰り返す
    num = int(input()) #標準入力
    if num == 0:break #入力値が0だった場合繰り返しを強制終了する
    else: #0でなければ
        num_list = [] #空リスト作成
        for _ in range(num): #入力回繰り返す
            num_list.append(int(input())) #標準入力をし、リストに加える
        num_list.sort() #リストを小さい順に並べる
        num_list.pop(-1) #リストの最高点を削除する
        num_list.pop(0) #リストの最低点を削除する
        num = sum(num_list) #リストの値を合計する
        num1 = len(num_list) #リストの長さを取得する
        print(int(num / num1)) #リストの平均を出力する
