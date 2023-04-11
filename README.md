**UNIVERSIDADE LUSÓFONA DE HUMANIDADES E TECNOLOGIAS**

*Linguagens de Programação I*

# Exercício Individual 3 - Trabalhos de Pintura
>Na resolução deste exercício deve ser utilizada a Linguagem de Programação C. Para além da correta implementação dos requisitos, tenha em conta os seguintes aspetos:
>- O código apresentado deve ser bem indentado. 
>- O código deve compilar sem erros ou *warnings* utilizando o *gcc* com as seguintes flags:
>- `-g -Wvla -Wall -Wpedantic -Wextra -Wdeclaration-after-statement`
>- Tenha em atenção os nomes dados das variáveis, para que sejam indicadores daquilo que as mesmas vão conter.
>- O trabalho deve ser desenvolvido e submetido de forma individual.

>Este exercício deverá ser submetido na plataforma Pandora até às 23h59 de dia XX de Abril e será contabilizado para a nota final da unidade curricular de acordo com os critérios disponibilizados na página da disciplina, concretamente nos slides da primeira aula.

>Todos os trabalhos serão comparados utilizando um sistema de deteção de plágio.


## Contexto

Um novo restaurante vegano estar a fazer sucesso em Lisboa. O problema é que não há como fazer reservas e a fila para conseguir uma mesa no dia pode ser um desafio. Pensando nisso o dono do restaurante pediu para que os alunos da disciplina elaborassem um programa que fizesse o controle da fila das pessoas em um dia de funcionamento normal do restaurante (14h-23h). O restaurante possue 4 mesas grandes (as mesas possuem numero ilimitado de pessoas) e que nunca são partilhadas enter grupos diferentes. Assim quando as mesas do restaurante estão todas ocupadas um grupo que acabar de chegar deve aguardar na fila até que chegue a sua vez. Apesar de ainda não ter um programa para gerir a fila, o dono do restaurante tem um controle significativo com as outras variaveis do restaurante. Ele nos informou que nenhuma mesa fica mais do que 2h em uso por um mesmo grupo. Sempre após duas horas uma equipe vai até a mesa e limpa-a para receber um novo grupo.
Há um funcionário que vai operar o programa e que tem informações de quantas pessoas chegaram e que horas chegaram.
Com essas duas informações o programa deve funcionar e atribuir automaticamente nas 4 mesas as pessoas que chegam e as pessoas da fila.

 
## Descrição

A tela de controle do programa deve ter os campos:


```
----------
Fila:
Hora Atual: 14
----------

Mesa 1: 0
Mesa 2: 0
Mesa 3: 0
Mesa 4: 0

Quantas pessoas chegaram?
1
Que horas chegaram?
14
```


A tela de controle acima sempre vai demonstrar quantas pessoas estão alocadas em uma mesa, sendo `0` o status que a mesa está disponivel. É importante também ter o controle de que horas a mesa iniciou para que ela fique disponivel após 2h.

A variavel `Hora Atual` é uma variavel de controle de tempo do restaurante que sempre é atualizada a partir do tempo em que novos grupos chegam.

O operador pode por exemplo dizer que 4 pessoas chegaram as 14h:


```
Quantas pessoas chegaram?
4
Que horas chegaram?
14
```

E em seguida pode dizer que 1 pessoa chegou as 15h:

```
Quantas pessoas chegaram?
1
Que horas chegaram?
15
```

Neste momento o horário do restaurante deve mudar de 14h para 15h. O operador do programa também pode atualizar o horário sem atribuição de grupo:

```
Quantas pessoas chegaram?
0
Que horas chegaram?
16
```
Para este caso ninguem será atribuido a nenhuma mesa ou fila e a hora do restaurante muda para 16h.

A hora lida sempre tem que ser maior ou igual a hora atual. Se isso não ocorrer basta apenas perguntar novamente `Que horas chegaram?`

Toda mesa tem em sua estrutura uma ocupação e uma hora de inicio. A hora de inicio é sempre a hora em que a mesa é iniciada com o grupo, independente da hora que ele chegou a fila.

Utilizem estrutura de dados tipo fila para controlar a fila do restaurante. Trabalhem com funcoes em separado para organizar melhor o codigo(Ex. Função que imprime, Função que faz a manutenção...)

## Honestidade Académica

Nesta disciplina, espera-se que cada aluno siga os mais altos padrões de honestidade académica. Trabalhos que sejam identificados como cópias serão anulados e os alunos envolvidos terão nota zero - quer tenham copiado, quer tenham deixado copiar.
Para evitar situações deste género, recomendamos aos alunos que nunca partilhem ou mostrem o seu código.
A decisão sobre se um trabalho é uma cópia cabe exclusivamente aos docentes da unidade curricular.
Os alunos são encorajados a discutir os problemas com outros alunos mas não deverão, no entanto, copiar códigos, documentação e relatórios de outros alunos. Em nenhuma circunstância deverão partilhar os seus próprios códigos, documentação e relatórios. De facto, não devem sequer deixar códigos, documentação e relatórios em computadores de uso partilhado.
