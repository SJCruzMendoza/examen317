 #Leemos el número de términos
term = 2 * (int(input('Introduzca cuantos terminos de la serie quiere calcular para π preferible nros grandes: ')))
# Iniciamos la variable que guardará el valor de Pi y el contador de términos de la serie
pi = 0
contador = 1
# Iteramos todos los términos de la serie, comenzando en 1, hasta el número de términos
# y avanzando 2 posiciones cada vez, debido a que la serie no necesita los denominadores pares.
# También debemos recordar que en la función range() se detiene uno antes del numero superior, 
# por eso se le suma 1 al número de términos a analizar
for t in range(1,term+1,2):
    # Checamos si el contador es par o no para determinar si se suma o se resta el término actual
    if contador % 2 :
        # Si es par se suma
        pi += 4/t
        # Se imprime el elemento de la serie y el valor actual de Pi
        print(f'Termino número {contador} ->     + 4 / {t}        Valor de π: {pi:>.20f}')
    else:
        # Si es impar se resta
        pi -= 4/t
        # Se imprime el elemento de la serie y el valor actual de Pi
        print(f'Termino número {contador} ->     - 4 / {t}        Valor de π: {pi:>.20f}')
    # Se incrementa el contador para el siguiente ciclo
    contador +=1  
