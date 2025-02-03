# Projeto BitDogLab - Controle de LEDs e Botões com RP2040

## Descrição
Este projeto utiliza a placa de desenvolvimento BitDogLab com o microcontrolador RP2040 para controlar uma matriz de LEDs WS2812 e um LED RGB, além de interagir com dois botões para incrementar e decrementar um valor exibido na matriz de LEDs. O foco principal é o uso de interrupções para tratar os eventos dos botões e implementar o debouncing via software.

## Componentes Utilizados
- **Matriz de LEDs WS2812 (5x5):** Conectada à GPIO 7.
- **LED RGB:** Conectado às GPIOs 11, 12 e 13.
- **Botão A:** Conectado à GPIO 5.
- **Botão B:** Conectado à GPIO 6.
- **Placa BitDogLab:** Utilizada como plataforma de desenvolvimento.

## Funcionalidades Implementadas
- **Botão A:** Incrementa o valor exibido na matriz de LEDs WS2812.
- **Botão B:** Decrementa o valor exibido na matriz de LEDs WS2812.
- **Interrupções:** Todas as funcionalidades relacionadas aos botões são implementadas utilizando rotinas de interrupção (IRQ).
- **Debouncing:** O tratamento do bouncing dos botões é feito via software.

## Estrutura do Código
### Arquivo button.h
Define as constantes e declarações necessárias para o funcionamento dos botões, incluindo os pinos dos botões, o tempo de debouncing e as variáveis globais.

#### Definições:
- **BUTTON_A_PIN:** Pino GPIO conectado ao Botão A (GPIO 5).
- **BUTTON_B_PIN:** Pino GPIO conectado ao Botão B (GPIO 6).
- **DEBOUNCE_DELAY:** Tempo de debouncing em milissegundos (200 ms).

#### Variáveis Globais:
- **counter:** Contador que armazena o valor atual exibido na matriz de LEDs.
- **prev_counter:** Armazena o valor anterior do contador para evitar atualizações desnecessárias.

#### Declarações de Funções:
- **button_init:** Função para inicializar os botões, configurando os pinos como entrada com pull-up e habilitando as interrupções.

### Arquivo button.c
Contém a implementação das funções relacionadas ao tratamento dos botões, incluindo a configuração de interrupções e o debouncing via software.

#### Funções Principais:
- **gpio_irq_callback:** Função de callback para tratar as interrupções geradas pelos botões. Realiza o debouncing e atualiza o valor do contador.
- **button_init:** Inicializa os botões, configurando os pinos como entrada com pull-up e habilitando as interrupções.

#### Variáveis:
- **last_a_interrupt_time e last_b_interrupt_time:** Armazenam o tempo da última interrupção para debouncing.
- **counter:** Contador que armazena o valor atual exibido na matriz de LEDs.
- **prev_counter:** Armazena o valor anterior do contador para evitar atualizações desnecessárias.

### Arquivo main.c
Contém a função principal do projeto, que inicializa os botões, a matriz de LEDs e o LED RGB, além de implementar a lógica para piscar o LED RGB.

## Como Executar o Projeto
### Configuração do Ambiente:
1. Certifique-se de ter o ambiente de desenvolvimento para o RP2040 configurado, incluindo o SDK da Raspberry Pi Pico.
2. Clone o repositório do projeto:
   ```bash
   git clone https://github.com/yaaggo/ledmatrix-counter-embarca.git
   ```

### Compilação:
1. Navegue até o diretório do projeto:
   ```bash
   cd ledmatrix-counter-embarca
   ```
2. Compile o projeto usando o CMake, ou então utilizando a extensão do Raspberry Pi:
   ```bash
   mkdir build && cd build && cmake .. && make
   ```

### Upload para a Placa:
1. Conecte a placa BitDogLab ao computador via USB.
2. Copie o arquivo `.uf2` gerado para a placa:

### Execução:
O projeto será executado automaticamente na placa. Pressione os botões A e B para incrementar e decrementar o valor exibido na matriz de LEDs.

## Vídeo de Demonstração
Assista ao vídeo de demonstração no YouTube: [Clique aqui](https://youtu.be/wk4uinr7teU)

